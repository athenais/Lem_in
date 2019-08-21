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

class Button(ToolToggleBase):
   def __init__(self, *args, **kwargs):
      super().__init__(*args, **kwargs)
      print("Init Button Class")

   def enable(self, *args):
      self.action(True)

   def disable(self, *args):
      self.action(False)

   def action():
      pass
    
def get_ants_per_path():
    dic = {}
    i = 1
    with open('ants.txt', 'r') as f:
        lines = f.readlines()
        for line in lines:
            dic[i] = int(line)
            i += 1
    return (dic)

class Ants(Button):
    description = "Ants"
    default_toggled = False
    image = r"fire-ant-png-4.png"

    def __init__(self, *args, fig, interval, graph, options, **kwargs):
        super().__init__(*args, **kwargs)
        self.graph = graph
        self.options = options
        self.ants = get_ants_per_path()
        self.length = self.ants[1] + len(self.graph['p'][1]) + 1 + 2
        self.fig = fig
        self.interval = interval


    # ants_path
    def action(self, state):
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

class Optimum(Button):
    description = "optimum paths"
    default_toggled = False

    def __init__(self, *args, graph, options, **kwargs):
        super().__init__(*args, **kwargs)
        self.options = options
        self.graph = graph
        self.length = len(self.graph['p'][len(self.graph['p']) - 1])

    
    # optimum_path
    def action(self, state):
        for ax in self.figure.get_axes():
            ax.clear()
        graph_list(0, self.options, self.graph, 0, 0, None)
        if state == True:
            for n in range(len(self.graph['p']) - 1):
                graph_list(2, self.options, self.graph, self.length, n, None)
        plt.gca().invert_yaxis()
        self.figure.canvas.draw()

class Shortest(Button):
    description = "shortest path"
    default_toggled = False

    def __init__(self, *args, graph, options, **kwargs):
        super().__init__(*args, **kwargs)
        self.options = options
        self.graph = graph
        self.length = len(self.graph['p'][0])

    def action(self, state):
        for ax in self.figure.get_axes():
            ax.clear()
        graph_list(0, self.options, self.graph, 0, 0, None)
        if state == True:
            graph_list(1, self.options, self.graph, self.length, 0, None)
        plt.gca().invert_yaxis()
        self.figure.canvas.draw()
