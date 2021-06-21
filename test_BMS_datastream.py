import unittest
import bms_input_handler


class test_streaming_bms_data(unittest.TestCase):

    def test_bms_param_generator(self):
        bms_param = bms_input_handler.generate_bms_parameters()
        self.assertTrue(bms_param is not None)

    def test_bms_param_within_limits(self):
        bms_param = bms_input_handler.generate_bms_parameters()
        self.assertTrue('temperature', bms_param['temperature'])
        self.assertTrue('soc', bms_param['soc'])

    def test_bms_parameters_in_generator(self):
        bms_param = bms_input_handler.generate_bms_parameters()
        bms_param_keys = list(bms_param.keys())
        self.assertTrue(bms_param_keys == ['temperature', 'soc'])
        self.assertFalse(bms_param_keys == ['charging_rate', 'soc'])

    def test_bms_stream_generator(self):
        self.assertTrue(len(bms_input_handler.generate_bms_readings_stream(10)) == 10)


    def test_bms_streaming_to_console(self):
        self.assertTrue(bms_input_handler.bsm_stream_console_output(30)== [True,30])



if __name__ == '__main__':
    unittest.main()
