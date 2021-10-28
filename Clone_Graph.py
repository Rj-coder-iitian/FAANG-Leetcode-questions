class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        # Empty graph
        if node == None:                        return
        cloned = {}
        currentLayer = [node]
        while len(currentLayer) != 0:
            nextLayer = []
            for toClone in currentLayer:
                if toClone in cloned:       continue
                temp = UndirectedGraphNode(toClone.label)
                nextLayer.extend(toClone.neighbors)
                cloned[toClone] = temp
            currentLayer = nextLayer
        # Assign the neighbors of new cloned nodes.
        for oldNode in cloned:
            newNode = cloned[oldNode]
            newNode.neighbors = [cloned[neighbor] for neighbor
                                                  in oldNode.neighbors]
