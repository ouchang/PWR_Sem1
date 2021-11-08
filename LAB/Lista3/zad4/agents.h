struct agent {
    int x, y; //wspołrzędne agenta
};

struct agent newagent(int x, int y);
void north(struct agent *a);
void south(struct agent *a);
void east(struct agent *a);
void west(struct agent *a);
double distance(struct agent a1, struct agent a2);
