class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);
        for(int i=0; i<numRows; i++) {
            r[i].resize(i+1);
            r[i][0] = r[i][i] = 1;
            for(int j=1; j<i; j++) {
                r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
        }
        return r;
    }
};

//Print Row with row index given
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret { 1 }, cur { 1 };
	    for(int i=1; i<=rowIndex; i++) {
		    ret.push_back(1);
		    for(int j=1; j<i; j++) {
			    ret[j] = cur[j] + cur[j - 1];
		    }
		    cur = ret;
	    }
	    return ret;
    }
};