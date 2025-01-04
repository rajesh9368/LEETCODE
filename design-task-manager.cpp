class TaskManager {
public:
set<pair<int, int>, greater<pair<int, int>>> pq;unordered_map<int, pair<int, int>> tm; 
//
public:
 void edit(int taskId, int newPriority) {
        int o = tm[taskId].first;
        pq.erase({o, taskId});
        tm[taskId].first = newPriority;
        pq.insert({newPriority, taskId});
    }















    TaskManager(vector<vector<int>>& tasks) {
        for(const auto& task : tasks) {
            int u= task[0],t = task[1],p = task[2];
            tm[t] = {p,u};       
            pq.insert({p, t});
        }
    }void add(int u,int t,int p) {
        tm[t] = {p, u};
        pq.insert({p,t});
    }
   
   
    int execTop() {
        if(pq.empty())  return -1;
        //
//
//
        auto tt = *pq.begin();
        int t= tt.second,u = tm[t].second;pq.erase(pq.begin());tm.erase(t);
        return u;
    }






 void rmv(int taskId) {
        int p = tm[taskId].first;
        pq.erase({p, taskId});  
        tm.erase(taskId);
    }
};   