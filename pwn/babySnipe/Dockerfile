FROM ubuntu:18.04

RUN apt update \
    && apt install -y socat

RUN useradd ctf && \
    mkdir /challenge

COPY challenge/flag.txt /flag.txt
COPY challenge /challenge

WORKDIR /challenge

RUN chown -R root:root . && \
    chmod +x babySnipe entrypoint.sh

USER ctf
EXPOSE 2033

ENTRYPOINT [ "./entrypoint.sh" ]
