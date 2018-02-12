//Vergleich-Fließkommazahlen



//Ein direkter Vergleich von Fleißkommawerten (double, float) ist immer falsch. Stattdessen sollte ein relatives Differenzenverfahren angewendet werden. 

//function () { ...

    const double epsilon = 1e-10;
    double difference = a - b;
    if ((difference > -epsilon) && (difference < epsilon)) {
        return true;
    }
    return false;
