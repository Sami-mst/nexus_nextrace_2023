FROM ubuntu:20.04

RUN apt-get update && \
    apt-get install -y openssh-server

RUN chmod o=wxt /tmp


RUN useradd -U -m -d /home/ctf -s /bin/bash ctf && \
    echo 'ctf:ctf' | chpasswd  && \ 
    find /home/ctf -type f -exec chown root:root {} \; && \ 
    find /home/ctf -type f -exec chmod 774 {} \;

COPY .hidden_flag.txt /home/ctf/.hidden_flag.txt

RUN chown  root:root /home/ctf 

EXPOSE 22

ENTRYPOINT service ssh start && tail -f /dev/null    
