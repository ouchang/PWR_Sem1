#include <stdio.h>
#include <math.h>

int main() {
    int n,x;
    int maxi=-2147483648, maxi_2=-2147483648;
    //max. element w tab, 2 z kolei max. elem. w tab

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &x);

        if(maxi < x) {
            maxi_2 = maxi;
            maxi = x;
        } else if((maxi_2 < x) && (maxi != x))
            maxi_2 = x;
    }

    printf("%d\n", maxi_2);
    
    return 0;
}
