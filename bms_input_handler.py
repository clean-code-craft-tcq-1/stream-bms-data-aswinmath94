import random
import time
bms_thresholds = {'temperature': {'min': 0, 'max': 45}, 'soc': {'min': 20, 'max': 80}}

#generate a single stream for two parameters in range
def generate_bms_parameters():
    battery_params = {}
    battery_params["temperature"] = round(random.uniform(bms_thresholds['temperature']['min'],
                                                         bms_thresholds['temperature']['max']),2)
    battery_params["soc"] = round(random.uniform(bms_thresholds['soc']['min'],
                                           bms_thresholds['soc']['max']),2)
    return battery_params

#generate stream of bms parameters
def generate_bms_readings_stream(max_count):
    bms_param_output_count = 0
    bms_output_stream = []
    while(bms_param_output_count < max_count):
        bms_output_stream.append(generate_bms_parameters())
        bms_param_output_count += 1
    return bms_output_stream

# check if generated bms parameter values are in limits
def is_bms_param_in_limits(param_name,param_value):
    lower_limit = bms_thresholds[param_name]['min']
    upper_limit = bms_thresholds[param_name]['max']

    if lower_limit<= param_value <=upper_limit:
        return True
    return False

#output bms stream to console and return the number of streams
def bsm_stream_console_output(no_of_readings):
    reading_count  = 0
    stream_end_flag = False
    bms_output_stream = generate_bms_readings_stream(no_of_readings)

    #output the bms stream to console
    for i in range(no_of_readings):
        print(bms_output_stream[i])
        time.sleep(1)
        reading_count+=1

    #check end of stream
    if i == reading_count - 1:
        stream_end_flag = True
    return [stream_end_flag,reading_count]
