#include <iostream>
using namespace std;

int mf[9][9], fg[25][25];

main(){
	int ff, gg, ww, hh, f, g, h, w, listo, rompe;

	cin>>w>>h;
	for(ww=0;ww<w;ww++)
		for(hh=0;hh<h;hh++)
			cin>>mf[ww][hh];

	cin>>f>>g;
	listo=0;
	for(ff=0;ff<f;ff++)
		for(gg=0;gg<g;gg++)
			cin>>fg[ff][gg];

	for(ff=0;ff<=f-w and listo==0;ff++)
		for(gg=0;gg<=g-h and listo==0;gg++){
			rompe=0;
			for(ww=0;ww<w and rompe==0;ww++)
				for(hh=0;hh<h and rompe==0;hh++){
					if(mf[ww][hh]==1 and fg[ff+ww][gg+hh]==1)
						rompe=1;
				}
			if(rompe==0)
				listo=1;
		}

	for(ff=0;ff<=f-w and listo==0;ff++)
		for(gg=0;gg<=g-h and listo==0;gg++){
			rompe=0;
			for(ww=0;ww<w and rompe==0;ww++)
				for(hh=0;hh<h and rompe==0;hh++){
					if(mf[ww][h-hh-1]==1 and fg[ff+ww][gg+hh]==1)
						rompe=1;
				}
			if(rompe==0)
				listo=1;
		}

	for(ff=0;ff<=f-w and listo==0;ff++)
		for(gg=0;gg<=g-h and listo==0;gg++){
			rompe=0;
			for(ww=0;ww<w and rompe==0;ww++)
				for(hh=0;hh<h and rompe==0;hh++){
					if(mf[w-ww-1][hh]==1 and fg[ff+ww][gg+hh]==1)
						rompe=1;
				}
			if(rompe==0)
				listo=1;
		}

	for(ff=0;ff<=f-w and listo==0;ff++)
		for(gg=0;gg<=g-h and listo==0;gg++){
			rompe=0;
			for(ww=0;ww<w and rompe==0;ww++)
				for(hh=0;hh<h and rompe==0;hh++){
					if(mf[w-ww-1][h-hh-1]==1 and fg[ff+ww][gg+hh]==1)
						rompe=1;
				}
			if(rompe==0)
				listo=1;
		}

	for(ff=0;ff<=f-h and listo==0;ff++)
		for(gg=0;gg<=g-w and listo==0;gg++){
			rompe=0;
			for(ww=0;ww<w and rompe==0;ww++)
				for(hh=0;hh<h and rompe==0;hh++){
					if(mf[ww][hh]==1 and fg[ff+hh][gg+ww]==1)
						rompe=1;
				}
			if(rompe==0)
				listo=1;
		}

	for(ff=0;ff<=f-h and listo==0;ff++)
		for(gg=0;gg<=g-w and listo==0;gg++){
			rompe=0;
			for(ww=0;ww<w and rompe==0;ww++)
				for(hh=0;hh<h and rompe==0;hh++){
					if(mf[w-ww-1][hh]==1 and fg[ff+hh][gg+ww]==1)
						rompe=1;
				}
			if(rompe==0)
				listo=1;
		}

	for(ff=0;ff<=f-h and listo==0;ff++)
		for(gg=0;gg<=g-w and listo==0;gg++){
			rompe=0;
			for(ww=0;ww<w and rompe==0;ww++)
				for(hh=0;hh<h and rompe==0;hh++){
					if(mf[ww][h-hh-1]==1 and fg[ff+hh][gg+ww]==1)
						rompe=1;
				}
			if(rompe==0)
				listo=1;
		}

	for(ff=0;ff<=f-h and listo==0;ff++)
		for(gg=0;gg<=g-w and listo==0;gg++){
			rompe=0;
			for(ww=0;ww<w and rompe==0;ww++)
				for(hh=0;hh<h and rompe==0;hh++){
					if(mf[w-ww-1][h-hh-1]==1 and fg[ff+hh][gg+ww]==1)
						rompe=1;
				}
			if(rompe==0)
				listo=1;
		}

		if(listo)
			cout<<"YES"<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;
}