FROM python:3.10-alpine

RUN apk update && \
    apk add socat 

RUN adduser --disabled-password --no-create-home ctf


COPY challenge/ /challenge/

WORKDIR /challenge/cjayl/here/

RUN chmod 500 entrypoint.sh

ENTRYPOINT ["./entrypoint.sh"]
