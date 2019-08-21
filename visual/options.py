# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    graph.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrunet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 20:16:57 by abrunet           #+#    #+#              #
#    Updated: 2019/06/19 20:59:58 by abrunet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import networkx as nx
import matplotlib.pyplot as plt

def set_options(G, ax, node_size, width, pos):
    options = {
        'pos': pos,
        'node_size': node_size,
        'alpha': 0.60,
        'width': width,
        'ax': ax,
    }
    return (options)

def get_options(G, vertices, ax, coord):
    #set edges width
    if vertices < 50:
        width = 10.0
    elif 50 <= vertices <= 1000:
        width = 5.0
    else:
        width = 3.0

    #set nodes size
    if vertices < 50:
        node_size = 500
    elif 50 <= vertices <= 1000:
        node_size = 150
    else:
        node_size = 100

    #set coordinates mapping
    if coord == 0 :
        if vertices <= 500:
            pos = nx.nx_pydot.pydot_layout(G, prog='fdp')  
        else:
            pos = nx.nx_pydot.pydot_layout(G, prog='sfdp')  
    else:
        if vertices <= 100:
            pos = nx.get_node_attributes(G, 'pos')
        else:
            pos = nx.nx_pydot.pydot_layout(G, prog='sfdp') 

    options = set_options(G, ax, node_size, width, pos)
    return (options)
