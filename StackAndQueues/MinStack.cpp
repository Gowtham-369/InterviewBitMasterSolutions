stack<int> st,minst;
int minn = INT_MAX;
MinStack::MinStack() {
    //c
    //e
    //C
    //E
    //reintialize all var
    while(!st.empty()){
        st.pop();
        minst.pop();
    }
    minn = INT_MAX;
}

void MinStack::push(int x) {
    if(st.empty()){
        minn = INT_MAX;
    }
    st.push(x);
    minn = min(minn,x);
    minst.push(minn);
}

void MinStack::pop() {
    if(!st.empty()){
        st.pop();
        // if(minn == minst.top())
        minst.pop();
        if(!minst.empty()){
        //update minn
            minn = min(minn,minst.top());
        }
    }
}

int MinStack::top() {
    if(st.empty()){
        return -1;
    }
    else{
        return st.top();
    }
}

int MinStack::getMin() {
    if(minst.empty()){
        return -1;
    }
    else{
        return minst.top();
    }
}

