class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for char in word:
            # If the character is missing, create a new node
            if char not in node.children:
                node.children[char] = TrieNode()
            # Move to the child node
            node = node.children[char]
            
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self.root
        for char in word:
            # If the character isn't found, the word doesn't exist
            if char not in node.children:
                return False
            # Move to the child node
            node = node.children[char]
            
        return node.is_end

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for char in prefix:
            # If the character isn't found, the prefix doesn't exist
            if char not in node.children:
                return False
            # Move to the child node
            node = node.children[char]
            
        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)