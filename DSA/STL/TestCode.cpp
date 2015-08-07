/*
Reminder from Part 1:
typedef vector<int> vi;
typedef vector<vi> vvi;
*/

 int N; // number of vertices 
 vvi W; // graph 
 vi V; // V is a visited flag 
 
 void dfs(int i) { 
       if(!V[i]) { 
            V[i] = true; 
            for_each(all(W[i]), dfs); 
       } 
 } 
  
 bool check_graph_connected_dfs() { 
       int start_vertex = 0; 
       V = vi(N, false); 
       dfs(start_vertex); 
       return (find(all(V), 0) == V.end()); 
 } 
 
 /*
Graph is considered to be stored as adjacent vertices list.
Also we considered graph undirected.
 
vvi is vector< vector<int> >
W[v] is the list of vertices adjacent to v
*/
 
 int N; // number of vertices
 vvi W; // lists of adjacent vertices
   
   
 bool check_graph_connected_bfs() { 
      int start_vertex = 0; 
      vi V(N, false); 
      queue<int> Q; 
      Q.push(start_vertex); 
      V[start_vertex] = true; 
      while(!Q.empty()) { 
           int i = Q.front(); 
           // get the tail element from queue
           Q.pop(); 
           tr(W[i], it) { 
                if(!V[*it]) { 
                     V[*it] = true; 
                     Q.push(*it); 
                } 
           } 
      } 
      return (find(all(V), 0) == V.end()); 
 } 
 
 
 typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

// Dijstra via priority_queue
 vi D(N, 987654321); 
      // distance from start vertex to each vertex

      priority_queue<ii,vector<ii>, greater<ii> > Q; 
      // priority_queue with reverse comparison operator, 
      // so top() will return the least distance
      // initialize the start vertex, suppose it’s zero
      D[0] = 0;
      Q.push(ii(0,0));

      // iterate while queue is not empty
      while(!Q.empty()) {

            // fetch the nearest element
            ii top = Q.top();
            Q.pop();
                        
            // v is vertex index, d is the distance
            int v = top.second, d = top.first;

            // this check is very important
            // we analyze each vertex only once
            // the other occurrences of it on queue (added earlier) 
            // will have greater distance
            if(d <= D[v]) {
                  // iterate through all outcoming edges from v
                  tr(G[v], it) {
                        int v2 = it->first, cost = it->second;
                        if(D[v2] > D[v] + cost) {
                              // update distance if possible
                              D[v2] = D[v] + cost;
                              // add the vertex to queue
                              Q.push(ii(D[v2], v2));

                        }
                  }
            }
      }
      
       vi D(N, 987654321);

      // start vertex
      set<ii> Q;
      D[0] = 0;
      Q.insert(ii(0,0));
 
      while(!Q.empty()) {

           // again, fetch the closest to start element 
           // from “queue” organized via set
           ii top = *Q.begin();
           Q.erase(Q.begin());
           int v = top.second, d = top.first;
 
           // here we do not need to check whether the distance 
           // is perfect, because new vertices will always
           // add up in proper way in this implementation

           tr(G[v], it) {
                int v2 = it->first, cost = it->second;
                if(D[v2] > D[v] + cost) {
                     // this operation can not be done with priority_queue, 
                     // because it does not support DECREASE_KEY
                     if(D[v2] != 987654321) {
                           Q.erase(Q.find(ii(D[v2],v2)));
                     }
                     D[v2] = D[v] + cost;
                     Q.insert(ii(D[v2], v2));
                }
           }
      }
      
      
      
