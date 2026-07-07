import heapq
from collections import defaultdict
from typing import List

class Twitter:
    def __init__(self):
        self.timestamp = 0
        self.tweets = defaultdict(list)
        self.following = defaultdict(set)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.timestamp -= 1
        self.tweets[userId].append((self.timestamp, tweetId))

    def getNewsFeed(self, userId: int) -> List[int]:
        feed = []
        users = self.following[userId] | {userId}
        
        for u in users:
            feed.extend(self.tweets[u][-10:])
            
        heapq.heapify(feed)
        return [heapq.heappop(feed)[1] for _ in range(min(10, len(feed)))]

    def follow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].discard(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)