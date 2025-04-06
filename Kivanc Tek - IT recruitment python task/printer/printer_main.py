import os
from fpp import Peripheral, Notifier, Listener
from Listener import Poli_Listener

PIPE_PATH = "Policumbent_pipe"
DEVICE_PATH = "peripheral_device"

if not os.path.exists(PIPE_PATH):
    os.mkfifo(PIPE_PATH)



peripheral = Peripheral(DEVICE_PATH)
listener = Poli_Listener(PIPE_PATH)
notifier = Notifier(peripheral, listener)
