int suma = 0;                       // atliekamas vieną kartą
cin >> n;                           //            vieną kartą
for(int i = 1; i <= n; i++) {       //            n kartų
    for(int j = 1; j <= n; j++) {   //            n^2 kartų
        cin >> a;                   //            n^2 kartų
        suma += a;                  //            n^2 kartų
    }
}
cout << suma << endl;               //            vieną kartą