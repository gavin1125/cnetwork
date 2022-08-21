Vagrant.configure("2") do |config|
  config.vm.box_check_update = false

  (1..2).each do |i|
    config.vm.define "worker#{i}" do |worker|
      worker.vm.box = "ubuntu/jammy64"
      worker.vm.hostname = "worker#{i}"
      worker.vm.network "private_network", ip: "192.168.56.7#{i}"
      worker.vm.provider "virtualbox" do |vb|
        vb.memory = 2048
        vb.cpus = 1
      end
     worker.vm.provision "shell", path: "scripts/common.sh"
    end
  end
end
