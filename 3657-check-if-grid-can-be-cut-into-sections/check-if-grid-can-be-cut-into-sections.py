class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        hor = []
        ver= []
        res=0

        for it in rectangles:
            hor.append((it[0],1))
            hor.append((it[2],-1))
            ver.append((it[1],1))
            ver.append((it[3],-1))
        hor.sort()
        ver.sort()
        sweep=0

        for it in hor:
            sweep+=it[1]
            if sweep==0:
                res+=1    
        if res>=3: return True
        sweep=0
        res=0
        for it in ver:
            sweep+=it[1]
            if sweep==0:
                res+=1

        if res>=3: return True
        return False           