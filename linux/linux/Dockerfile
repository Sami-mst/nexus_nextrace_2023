FROM python:3.10

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends openssh-server systemd rsyslog findutils

RUN useradd -M -s /bin/bash ctf \
    && echo 'ctf:ctf' | chpasswd \
WORKDIR /home/ctf
COPY challenge/* /opt/
COPY challenge/sshd_config /etc/ssh/sshd_config


RUN chmod 444 /opt/* 


ENTRYPOINT service ssh start \
    && tail -f --retry 
