import unittest
import bms_input_handler


class test_streaming_bms_data(unittest.TestCase):

    def test_bms_param_generator(self):
        bms_param = bms_input_handler.generate_bms_parameters()
        self.assertTrue(bms_param is not None)

    def test_bms_parameters_in_generator(self):
        bms_param = bms_input_handler.generate_bms_parameters()
        bms_param_keys = list(bms_param.keys())
        self.assertTrue(bms_param_keys == ['temperature', 'soc'])
        self.assertFalse(bms_param_keys == ['charging_rate', 'soc'])

    def test_streaming_bms_param(self):
        bms_input_handler.stream_bms_readings(10)


if __name__ == '__main__':
    unittest.main()
