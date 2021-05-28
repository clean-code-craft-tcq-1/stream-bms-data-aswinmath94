import random
import time
bms_thresholds = {'temperature': {'min': 0, 'max': 45}, 'soc': {'min': 20, 'max': 80}}


def generate_bms_parameters():
    battery_params = {}
    battery_params["temperature"] = round(random.uniform(bms_thresholds['temperature']['min'],
                                                         bms_thresholds['temperature']['max']),2)
    battery_params["soc"] = round(random.uniform(bms_thresholds['soc']['min'],
                                           bms_thresholds['soc']['max']),2)
    return battery_params

def stream_bms_readings(max_count):
    bms_param_output_count = 0
    while(bms_param_output_count < max_count):
        print(generate_bms_parameters())
        bms_param_output_count += 1
        time.sleep(1)

def is_bms_param_in_limits(param_name,param_value):
    lower_limit = bms_thresholds['param_name']['min']
    upper_limit = bms_thresholds['param_name']['max']

    if lower_limit<= param_value <=upper_limit:
        return True
    return False
