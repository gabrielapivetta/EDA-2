int intercala_sort(int *a, int la, int ra, int *b, int lb, int rb){
	int ta = (ra-la+1);
	int tb = (rb-lb+1);
	int *c = malloc(sizeof(int)*(ta+tb));
	int lc=0;
	int rc=(ta+tb-1); 
	int ia = la;
	int ib = lb;
	int ic = 0;
	
	while(ia<=ra && ib<=rb){
		if(a[ia] <= b[ib])
			c[ic++] = a[ia++];
		else
			c[ic++] = b[ib++];
	}
	while(ia<=ra)
		c[ic++] = a[ia++];
	while(ib<=rb)
		c[ic++] = b[ib++];
		
	return c;
}
