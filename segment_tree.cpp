#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class segtree{

    vector<int> seg;
    public: segtree(int n){
        seg.resize(4*n);
    }

    void buildsg(int idx, int low, int high, vector<int>& arr){
        if(low == high){
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high)/2;
        buildsg(idx*2+1, low, mid, arr);
        buildsg(idx*2+2, mid+1, high, arr);
        seg[idx] = min(seg[idx*2+1], seg[idx*2+2]);
    }


    int querysg(int idx, int low, int high, int l, int r){
        if(l>high || r<low){
            return INT_MAX;
        }
        if(low>=l && high<=r)return seg[idx];
        int mid = (low+high)/2;
        int left = querysg(idx*2+1, low, mid, l, r);
        int right = querysg(idx*2+2, mid+1, high, l, r);
        return min(left, right);
    }

    void updatesg(int idx, int low, int high, int ptr, int val){
        if(low == high){
            seg[idx] = val;
            return;
        }

        int mid = (low+high)/2;
        if(ptr<=mid) updatesg(idx*2+1, low, mid, ptr, val);
        else updatesg(idx*2+2, mid+1, high, ptr, val);
        seg[idx] = min(seg[idx*2+1], seg[idx*2+2]);
    }
};



