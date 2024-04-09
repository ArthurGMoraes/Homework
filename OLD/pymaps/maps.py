import folium
from folium.plugins import MarkerCluster

aux = []

with open ('C:/Users/gdemo/OneDrive/Área de Trabalho/Homework/OLD/pymaps/mapapy.csv') as csv:
    csv.readline()
    for linha in csv:
        #print(linha)
        nova = [float (val) for val in linha.split(',')]
        aux.append(nova)

mapa = folium.Map(location=[-19.9320924, -43.9357563])

maker_cluster = MarkerCluster().add_to(mapa)
print(aux[0])
dados = aux

i=0

for aux2 in dados:
    folium.Marker(location=[aux[i][1], aux[i][0]]).add_to(maker_cluster)
    i=i+1
mapa.save("C:/Users/gdemo/OneDrive/Área de Trabalho/Homework/OLD/pymaps/mapa2.html")