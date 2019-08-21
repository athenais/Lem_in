# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    graph.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrunet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 20:16:57 by abrunet           #+#    #+#              #
#    Updated: 2019/06/20 11:40:57 by abrunet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from matplotlib.backend_tools import ToolBase, ToolToggleBase
import matplotlib.animation as animation
import matplotlib.pyplot as plt
from draw import graph_list

def get_ants_per_path():
    dic = {}
    i = 1
    with open('ants.txt', 'r') as f:
        lines = f.readlines()
        for line in lines:
            dic[i] = int(line)
            i += 1
    return (dic)

class Ants(ToolToggleBase):
    description = "Ants"
    default_toggled = False
    image = r"fire-ant-png-4.png"

    def __init__(self, *args, fig, interval, graph, options, **kwargs):
        self.graph = graph
        self.options = options
        self.ants = get_ants_per_path()
        self.length = self.ants[1] + len(self.graph['p'][1]) + 10
        self.fig = fig
        self.interval = interval
        super().__init__(*args, **kwargs)
    
    def enable(self, *args):
        self.ants_path(True)

    def disable(self, *args):
        self.ants_path(False)

    def ants_path(self, state):
        for ax in self.figure.get_axes():
            ax.clear()
        graph_list(0, self.options, self.graph, 0, 0, None)
        if state == True:
            def update(i):
                for ax in self.figure.get_axes():
                    ax.clear()
                graph_list(0, self.options, self.graph, 0, 0, None)
                for n in range(len(self.graph['p']) - 1):
                    graph_list(3, self.options, self.graph, i, n, self.ants)
                plt.gca().invert_yaxis()
                self.figure.canvas.draw()
            ani = animation.FuncAnimation(self.fig, update, frames=self.length, interval=self.interval, repeat=False)
        plt.gca().invert_yaxis()
        self.figure.canvas.draw()

class Optimum(ToolToggleBase):
    description = "optimum paths"
    default_toggled = False

    def __init__(self, *args, graph, options, **kwargs):
        self.options = options
        self.graph = graph
        self.length = len(self.graph['p'][len(self.graph['p']) - 1])
        super().__init__(*args, **kwargs)
    
    def enable(self, *args):
        self.optimum_path(True)

    def disable(self, *args):
        self.optimum_path(False)

    def optimum_path(self, state):
        for ax in self.figure.get_axes():
            ax.clear()
        graph_list(0, self.options, self.graph, 0, 0, None)
        if state == True:
            for n in range(len(self.graph['p']) - 1):
                graph_list(2, self.options, self.graph, self.length, n, None)
        plt.gca().invert_yaxis()
        self.figure.canvas.draw()

class Shortest(ToolToggleBase):
    description = "shortest path"
    default_toggled = False

    def __init__(self, *args, graph, options, **kwargs):
        self.options = options
        self.graph = graph
        self.length = len(self.graph['p'][0])
        super().__init__(*args, **kwargs)

    def enable(self, *args):
        self.shortest_path(True)

    def disable(self, *args):
        self.shortest_path(False)

    def shortest_path(self, state):
        for ax in self.figure.get_axes():
            ax.clear()
        graph_list(0, self.options, self.graph, 0, 0, None)
        if state == True:
            graph_list(1, self.options, self.graph, self.length, 0, None)
        plt.gca().invert_yaxis()
        self.figure.canvas.draw()
