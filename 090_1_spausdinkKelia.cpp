void spausdinkKelia (int u) {
    if (pirmine[u] != -1) // jei tai nėra pradinė viršūnė (nuo kurios pradėjom paiešką gilyn)
        spausdinkKelia (pirmine[u]);
    cout << u << "\n";
}
