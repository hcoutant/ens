init () {
    creer_semaphore (Secrivain, 1) ;
    creer_semaphore (Smutex, 1) ;
    nlect = 0 ;
}
ecrivain () {
    P (Secrivain) ;
    /* ecriture */
    V (Secrivain) ;
}
lecteur () {
    P (Smutex) ;
    nlect++ ;
    if (nlect == 1) {
	P (Secrivain)
    }
    V (Smutex) ;
    /* lecture */
    P (Smutex) ;
    nlect-- ;
    if (nlect == 0) {
	V (Secrivain)
    }
    V (Smutex) ;
}
