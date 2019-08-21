# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    graph.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrunet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 20:16:57 by abrunet           #+#    #+#              #
#    Updated: 2019/06/19 22:57:05 by abrunet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import networkx as nx

def draw_graph(mode, G, options, nodelist, edgelist, colors):
    if mode == 0:
        nx.draw_networkx_edges(G, **options, edge_color=colors['edge_std'])
        nx.draw_networkx_nodes(G, **options, node_color=colors['node_std'])
    elif mode == 1:
        nx.draw_networkx_nodes(G, **options, nodelist=nodelist, node_color=colors['short'])
        nx.draw_networkx_edges(G, **options, edgelist=edgelist, edge_color=colors['short'])
    elif mode == 2:
        nx.draw_networkx_nodes(G, **options, nodelist=nodelist, node_color=colors['opti'])
        nx.draw_networkx_edges(G, **options, edgelist=edgelist, edge_color=colors['opti'])
    elif mode == 3:
        nx.draw_networkx_nodes(G, **options, nodelist=nodelist, node_color=colors['ants'])
        nx.draw_networkx_edges(G, **options, edgelist=edgelist, edge_color=colors['ants'])

def graph_list(mode, options, graph, l, idx, ants):
    p = graph['p']
    c = graph['colors']
    G = graph['G']
    nodelist = None
    edgelist = None

    if mode == 1:
        nodelist = p[idx][(l - l):(l + 1)]
        edgelist = [nodelist[k:k+2] for k in range(len(nodelist) - 1)]
    if mode == 2:
        nodelist = p[idx + 1][(l - l):(l + 1)]
        edgelist = [nodelist[k:k+2] for k in range(len(nodelist) - 1)]
    if mode == 3:
        if (ants[idx + 1] - l >= 0):
            nodelist = p[idx + 1][(l - l):(l + 1)]
        else:
            nodelist = p[idx + 1][(l - ants[idx + 1] - 1):(l + 1)]
        edgelist = [nodelist[k:k+2] for k in range(len(nodelist) - 1)]
    draw_graph(mode, G, options, nodelist, edgelist, c)


