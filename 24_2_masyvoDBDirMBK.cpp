int visuDBD = 0; // po pirmo žingsnio taps lygiu m[0]
for(int i = 0; i < n; i++) {
    visuDBD = DBD(visuDBD, abs(m[i]));
}

int visuMBK = 1; // po pirmo žingsnio taps lygiu m[0]
for(int i = 0; i < n; i++) {
    visuMBK = MBK(visuMBK, abs(m[i]));
}
