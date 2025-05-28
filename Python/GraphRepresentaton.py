import networkx as nx
import matplotlib.pyplot as plt

# Create an undirected graph
G = nx.Graph()

# Add edges along with their weights
edges = [
    (0, 1, 10),
    (0, 4, 5),
    (1, 2, 1),
    (1, 4, 2),
    (2, 3, 4),
    (3, 0, 7),
    (4, 1, 3),
    (4, 2, 9),
    (4, 3, 2)
]

for u, v, w in edges:
    G.add_edge(u, v, weight=w)

# Define position of nodes for better visualization
pos = nx.spring_layout(G)

# Draw the graph
nx.draw(G, pos, with_labels=True, node_size=700, node_color='lightblue', font_size=15, edge_color='gray')

# Draw edge labels
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)

plt.title("Undirected Graph Representation")
plt.show()
