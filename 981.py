from collections import defaultdict

class TimeMap:
    def __init__(self):
        self.map = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:
        recs = self.map[key]
        res = ""
        if recs == []:
            return res

        l, r = 0, len(recs) - 1
        while l <= r:
            mid = (l + r) // 2
            if recs[mid][1] <= timestamp:
                res = recs[mid][0]
                l = mid + 1
            else:
                r = mid - 1
        return res

timeMap = TimeMap()
timeMap.set("love", "high", 10)
timeMap.set("love", "low", 20)

print(timeMap.get("love", 5))
print(timeMap.get("love", 10))
print(timeMap.get("love", 15))
print(timeMap.get("love", 20))
print(timeMap.get("love", 25))

