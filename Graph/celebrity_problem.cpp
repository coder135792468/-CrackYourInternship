    int celebrity(int M[][], int n)
    {
    	// code here
    	int idx = 0;
    	for(int i = 0; i < n; i++) {
    	    if(M[idx][i] == 1) {
    	        idx = i;
    	    }
    	}
    	
    	for(int i = 0; i < n; i++) {
    	    if(i != idx && (M[idx][i] == 1 || M[i][idx] == 0)) {
    	        return -1;
    	    }
    	}
    	
    	return idx;
    }
}