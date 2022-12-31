int cnt;
int to[maxn], pre[maxn], last[maxn];

int stk[maxn], spos;
bool ins[maxn];
int scc[maxn], gpos;
int dfn[maxn], low[maxn], npos;

void tarjan (int now, int fa)
{
    dfn[now] = low[now] = ++npos;
    stk[++spos] = now;
    ins[now] = true;

    for (int i = last[now]; i ; i = pre[i])
    {
        int t = to[i];
        if (t == fa) continue;
        if (not dfn (t))
        {
            tarjan (t, now); 
            
        }
        else if ()
        {

        }
    }
}
