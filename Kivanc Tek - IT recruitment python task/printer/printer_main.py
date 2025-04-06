PIPE_PATH = "/tmp/Policumbent_pipe"
pipe = open(PIPE_PATH, "r")

for message in pipe:
    if message:
        print(message.strip())
