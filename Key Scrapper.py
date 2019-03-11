from requests import get
from bs4 import BeautifulSoup
import os

song_dir = r"your directory here"

lista = os.listdir(song_dir)
original = os.listdir(song_dir)

i = 0
for x in lista:
    lista[i] = lista[i][:-4].translate(str.maketrans('','','1234567890-'))
    lista[i] = lista[i].split()
    print(lista[i])
    i = i + 1
    
y = 0
for i in range(len(lista)):
    x = 1
    nombre = lista[y][0]
    for i in range(len(lista[y])-1):
        nombre += '+' + lista[y][x]
        x = x + 1
    url = 'https://tunebat.com/Search?q=' + nombre
    response = get(url)
    html_soup = BeautifulSoup(response.text, 'html.parser')
    camelot = html_soup.find_all('div', class_ = 'row search-attribute-value')
    if len(camelot) is not 0:
        first_movie = camelot[1]
        path = song_dir
        os.rename(os.path.join(path, original[y]), os.path.join(path, first_movie.text + ' ' + original[y]))        
        print(lista[y])
        print(first_movie.text)
    y = y+1