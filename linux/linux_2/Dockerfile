FROM python:3.10

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends openssh-server sudo systemd rsyslog 

RUN useradd -M -s /bin/bash admin \
    && useradd -M -s /bin/bash ctf \
    && echo 'ctf:ctf' | chpasswd \
    && usermod -aG sudo ctf
WORKDIR /home/ctf
COPY challenge/flag.txt /home/ctf
COPY challenge/sudoers /etc/sudoers
COPY challenge/sshd_config /etc/ssh/sshd_config


RUN chown admin:admin /home/ctf/flag.txt \
    && chmod 440 /home/ctf/flag.txt 


ENTRYPOINT service ssh start \
    && tail -f --retry 
