# Libs importadas
import requests
import json
import urllib3
from urllib.parse import quote
from urllib.request import urlopen
import wave
from contextlib import closing
import pyaudio
import time
from datetime import date
from datetime import timedelta

# Configuração padrão do player de áudio.
player = None
def playwav(path_or_file):
    global player
    if player is None:
        player = pyaudio.PyAudio()
    with closing(wave.open(path_or_file, 'rb')) as wavfile, \
         closing(player.open(
             format=player.get_format_from_width(wavfile.getsampwidth()),
             channels=wavfile.getnchannels(),
             rate=wavfile.getframerate(),
             output=True)) as stream:
        while True:
            data = wavfile.readframes(1024) # read 1024 frames at once
            if not data: # EOF
                break
            stream.write(data)



# Loop de requests ao Node-Red ('main')
while(True):
    print("start")
    # GET - 'usuario' array.
    res = requests.get('http://192.168.128.249:1880/usuario')
    
    print(res)
    # Seleciona o primeiro e único usuário do array
    response = json.loads(res.text)[0]
    print(response)
    tema = response['tema']
    isPT = response['portugues']
    #print(isPT)
    intervalo = int(response['intervalo'])
    
    if(response['caixinha_state']==False):
        print("Eva desligada.")
        time.sleep(10)
    else:
        # Armazena a data atual (menos um dia)
        data = date.today() - timedelta(days = 1)
        # GET - audio WAV (params --> tema e data)

        url = "http://192.168.128.249:1880/audio?tema=%s&data=%s&portugues=%s"%(tema.replace(' ', '%20'), data, isPT)
        print(url)
        playwav(urlopen(url.format(**vars())))
            
        # Respeita o intervalo configurado pelo aplicativo
        time.sleep(intervalo)
    