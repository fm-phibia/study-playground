# TestPj

# 必要なコマンド

yum update -y && \
  yum install -y wget unzip findutils && \
  yum clean all

wget https://services.gradle.org/distributions/gradle-8.3-bin.zip && \
  unzip gradle-8.3-bin.zip -d /opt/ && \
  rm gradle-8.3-bin.zip && \
  ln -s /opt/gradle-8.3/bin/gradle /usr/bin/gradle


wget https://services.gradle.org/distributions/gradle-7.5.1-bin.zip && \
  unzip gradle-7.5.1-bin.zip -d /opt/ && \
  rm gradle-7.5.1-bin.zip && \
  ln -s /opt/gradle-7.5.1/bin/gradle /usr/bin/gradle