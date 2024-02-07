中国剩余定理：一个解为$x=\sum_{i=1}^ka_i\frac{M}{m_i}t_i$通解为$x+i*M$最小非负整数解为$(x\%M+M)\%M$
扩展：已求出前$k-1$个方程组成的同余方程组的一个解$x$,$M=lcm_{i-1}^{k-1}$，则前m个方程组的通解为$x+i*M$
加入第k个方程后，需求t，使得$x+t*M=a_k\quad mod\quad m_k$,即$t*M=a_k-x (mod\quad m_k)$，所以$x_k=x+t*M$