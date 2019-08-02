
#define MAXM 100005
#define MAXL 300005

int N, M;
char S[MAXL], buf[MAXL];

struct NODE {
	NODE () : is_end(0), count(0), f(0), o(0) { for(int i=0;i<26;i++) nxt[i] = 0; }
	bool is_end; int count;
	NODE *nxt[26], *f, *o;
} *root;
NODE *my_end_node[MAXM];


int main()
{
	scanf("%s%d", S+1, &M); N = strlen(S+1);
	root = new NODE();
	for(int i=1;i<=M;i++) {
		scanf("%s", buf+1); int n = strlen(buf+1);
		NODE *now = root;
		for(int j=1;j<=n;j++) {
			int c = buf[j] - 'a';
			if(!now->nxt[c]) now->nxt[c] = new NODE();
			now = now->nxt[c];
		}
		now->is_end = 1;
		my_end_node[i] = now;
	}
	queue <NODE*> que;
	for(int i=0;i<26;i++) if(root->nxt[i]) {
		root->nxt[i]->f = root;
		que.push(root->nxt[i]);
	}
	while(!que.empty()) {
		NODE *q = que.front(); que.pop();
		if(q->is_end) q->o = q;
		else q->o = q->f->o;
		for(int i=0;i<26;i++) if(q->nxt[i]) {
			NODE *t = q->nxt[i];
			t->f = q->f;
			while(t->f != root && !t->f->nxt[i]) t->f = t->f->f;
			if(t->f->nxt[i]) t->f = t->f->nxt[i];
			que.push(t);
		}
	}
	NODE *now = root;
	for(int i=1;i<=N;i++) {
		int c = S[i] - 'a';
		while(now != root && !now->nxt[c]) now = now->f;
		if(now->nxt[c]) now = now->nxt[c];
		if(now->o) {
			now->o->count++;
		}
	}

	vector <NODE*> order;
	que.push(root);
	while(!que.empty()) {
		NODE *q = que.front(); que.pop();
		order.pb(q);
		for(int i=0;i<26;i++) if(q->nxt[i]) que.push(q->nxt[i]);
	}
	reverse(all(order));
	for(NODE* now: order) {
		if(now->is_end && now->f->o) now->f->o->count += now->count;
	}

	for(int i=1;i<=M;i++)
		printf("Pattern #%d occurs %d times\n", i, my_end_node[i]->count);

}
