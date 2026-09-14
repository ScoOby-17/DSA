class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec1 = [x1,y1,x2,y2] → bottom-left to top-right
        // rec2 = [x1,y1,x2,y2]

        // Non-overlap cases:
        // rec1 completely left of rec2
        // rec1 completely right of rec2
        // rec1 completely below rec2
        // rec1 completely above rec2

        if(rec1[2] <= rec2[0]) return false;  // rec1 right <= rec2 left
        if(rec2[2] <= rec1[0]) return false;  // rec2 right <= rec1 left
        if(rec1[3] <= rec2[1]) return false;  // rec1 top <= rec2 bottom
        if(rec2[3] <= rec1[1]) return false;  // rec2 top <= rec1 bottom

        return true;
    }
};