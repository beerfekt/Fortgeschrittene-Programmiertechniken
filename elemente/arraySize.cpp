    ComplexNumber complexnumbers [3] = {c1,c2,c3};

    //sizeof gibt anzahl bytes aus, daher die gesamtanzahl der bytes durch die bytes einer position = anzahl der positionen
    int complexSize = sizeof complexnumbers / sizeof complexnumbers[0];
