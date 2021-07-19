for s in open(0):
 M,P,L,E,R,S,N=map(int,s.split())
 exec('N,M,P,L=P//S,L//R,M*E;'*N)
 print(M)