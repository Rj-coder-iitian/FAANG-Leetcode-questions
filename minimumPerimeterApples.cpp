#define ll long long int
    long long minimumPerimeter(long long neededApples) {
        ll totalApplesInSquare = 0;
        ll unit =0;
        while(neededApples>totalApplesInSquare){
        unit++;

        totalApplesInSquare += 12*pow(unit,2);
        }

        return unit*8;
    }
