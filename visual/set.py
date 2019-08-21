# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    set.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrunet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 20:16:22 by abrunet           #+#    #+#              #
#    Updated: 2019/06/19 22:12:57 by abrunet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import networkx as nx
from graph import graph
import subprocess 
import os
import sys

def read_data():
    data = {}
    if os.path.exists('data.txt') == False:
        raise Exception('Invalid Map')
    with open('data.txt', 'r') as f:
        lines = f.readlines()
        data['ants'] = int(lines[0].strip('\n'))
        data['vertices'] = int(lines[1].strip('\n'))
        data['start'] = lines[2].strip('\n')
        data['end'] = lines[3].strip('\n')
    return (data)

def read_paths():
    paths = []
    lst = []
    if os.path.exists('paths.txt') == False:
        raise Exception('Invalid Map')
    with open('paths.txt', 'r') as f:
        lines = f.readlines()
        for line in lines:
            if (line.strip('\n')):
                lst.append(line.strip('\n'))
            else:
                paths.append(lst)
                lst = []
    return (paths)
                
def read_output(lines, G):
    coord = 0
    for line in lines:
        if (line and '\033' not in line[0]):
            if (line.startswith(('#', 'L')) == False):
                if (line.find(' ') != -1):
                    data = line.split(' ')
                    name = data[0]
                    x = int(data[1])
                    y = int(data[2])
                    coord += x + y
                    G.add_node(name, pos=(x, y))
                elif (line.find('-') != -1):
                    e = line.split('-')
                    e = (tuple((e[0], e[1])))
                    G.add_edge(*e)
        else:
            return (coord)
        print(line)
    return (coord)

def clear_files():
    if os.path.exists('paths.txt'):
        os.remove('paths.txt')
    if os.path.exists('data.txt'):
        os.remove('data.txt')
    if os.path.exists('ants.txt'):
        os.remove('ants.txt')

if __name__ == '__main__':
    clear_files()
    if (os.path.exists('../lem-in') == False):
        subprocess.call('make -C ..', shell=True)
    cmd = '../lem-in -v'
    p = subprocess.check_output(cmd, shell=True)
    output = p.decode("utf-8")
    lines = output.split('\n')
    G = nx.Graph()
    color=sys.argv[1].strip() if len(sys.argv) == 2 else None
    coord = read_output(lines, G)
    try:
        data = read_data()
        paths = read_paths()
        graph(G, coord, paths, data, color)
        clear_files()
    except Exception as e:
        print(e)
