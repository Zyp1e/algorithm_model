/*https://www.luogu.com.cn/problem/P5357*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef char chr;
typedef deque<int> dic;
const int maxN = 2e5;
const int maxS = 2e5;
const int maxT = 2e6;

int n;
chr s[maxS + 10];
chr t[maxT + 10];
int cnt[maxN + 10];

struct AhoCorasickAutomaton {
    struct Node {
        int son[30];
        int val;
        int fail;
        int head;
        dic index;
    } node[maxS + 10];

    struct Edge {
        int head;
        int next;
    } edge[maxS + 10];

    int root;
    int ncnt;
    int ecnt;

    void Insert(chr *str, int i) {
        int u = root;
        int m=strlen(str+1);
        for (int i = 1; i<=m; i++) {
        if (node[u].son[str[i] - 'a' + 1] == 0)
            node[u].son[str[i] - 'a' + 1] = ++ncnt;
        u = node[u].son[str[i] - 'a' + 1];
        }
        node[u].index.push_back(i);
        return;
    }

    void Build() {
        dic q;
        for (int i = 1; i <= 26; i++)
        if (node[root].son[i]) q.push_back(node[root].son[i]);
        while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (int i = 1; i <= 26; i++) {
            if (node[u].son[i]) {
                node[node[u].son[i]].fail = node[node[u].fail].son[i];
                q.push_back(node[u].son[i]);
            } else {
                node[u].son[i] = node[node[u].fail].son[i];
            }
        }
        }
        return;
    }

    void Query(chr *str) {
        int u = root;
        int m=strlen(str+1);
        for (int i = 1; i<=m; i++) {
            u = node[u].son[str[i] - 'a' + 1];
            node[u].val++;
        }
        return;
    }

    void addEdge(int tail, int head) {
        ecnt++;
        edge[ecnt].head = head;
        edge[ecnt].next = node[tail].head;
        node[tail].head = ecnt;
        return;
    }

    void DFS(int u) {
        for (int e = node[u].head; e; e = edge[e].next) {
            int v = edge[e].head;
            DFS(v);
            node[u].val += node[v].val;
        }
        for (auto i : node[u].index) cnt[i] += node[u].val;
        return;
    }

    void FailTree() {
        for (int u = 1; u <= ncnt; u++) addEdge(node[u].fail, u);
        DFS(root);
        return;
    }
} ACM;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> (s + 1);
        ACM.Insert(s, i);
    }
    ACM.Build();
    cin >> (t + 1);
    ACM.Query(t);
    ACM.FailTree();
    for (int i = 1; i <= n; i++)cout << cnt[i] << endl;
    return 0;
}
/*
#include <bits/stdc++.h>
#define maxn 8000001
using namespace std;
char s[maxn];
int n, cnt, vis[maxn], rev[maxn], indeg[maxn], ans;

struct trie_node {
    int son[27];
    int fail;
    int flag;
    int ans;

    void init() {
        memset(son, 0, sizeof(son));
        fail = flag = 0;
    }
} trie[maxn];

queue<int> q;

void init() {
    for (int i = 0; i <= cnt; i++) trie[i].init();
    for (int i = 1; i <= n; i++) vis[i] = 0;
    cnt = 1;
    ans = 0;
}

void insert(char *s, int num) {
    int u = 1, len = strlen(s);
    for (int i = 0; i < len; i++) {
        int v = s[i] - 'a';
        if (!trie[u].son[v]) trie[u].son[v] = ++cnt;
        u = trie[u].son[v];
    }
    if (!trie[u].flag) trie[u].flag = num;
    rev[num] = trie[u].flag;
    return;
}

void getfail(void) {
    for (int i = 0; i < 26; i++) trie[0].son[i] = 1;
    q.push(1);
    trie[1].fail = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int Fail = trie[u].fail;
        for (int i = 0; i < 26; i++) {
        int v = trie[u].son[i];
        if (!v) {
            trie[u].son[i] = trie[Fail].son[i];
            continue;
        }
        trie[v].fail = trie[Fail].son[i];
        indeg[trie[Fail].son[i]]++;
        q.push(v);
        }
    }
}

void topu() {
    for (int i = 1; i <= cnt; i++)
        if (!indeg[i]) q.push(i);
        while (!q.empty()) {
        int fr = q.front();
        q.pop();
        vis[trie[fr].flag] = trie[fr].ans;
        int u = trie[fr].fail;
        trie[u].ans += trie[fr].ans;
        if (!(--indeg[u])) q.push(u);
    }
}

void query(char *s) {
    int u = 1, len = strlen(s);
    for (int i = 0; i < len; i++) u = trie[u].son[s[i] - 'a'], trie[u].ans++;
}

int main() {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i++) scanf("%s", s), insert(s, i);
    getfail();
    scanf("%s", s);
    query(s);
    topu();
    for (int i = 1; i <= n; i++) cout << vis[rev[i]] << std::endl;
    return 0;
}*/