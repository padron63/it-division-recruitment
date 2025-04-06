from fpp import Listener

class Poli_Listener(Listener):
    
    def __init__(self, pipe_path):
        self.pipe_path = pipe_path

    def on_message_received(self, message):
        pipe = open(self.pipe_path, "w")
        pipe.write(message) 
