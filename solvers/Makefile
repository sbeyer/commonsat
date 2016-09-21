all: compile_all

LINGELING_VERSION=bal-2293bef-151109

minisat:
	git clone https://github.com/niklasso/minisat

cryptominisat:
	git clone https://github.com/msoos/cryptominisat.git

lingeling:
	curl -o ll.tar.gz http://fmv.jku.at/lingeling/lingeling-$(LINGELING_VERSION).tar.gz
	tar xf ll.tar.gz
	mv lingeling-$(LINGELING_VERSION) lingeling
	$(RM) ll.tar.gz

.PHONY: compile_all

compile_minisat: minisat
	cd minisat && mkdir -p build && cd build && cmake ..
	$(MAKE) -C minisat/build
	echo "Removing this file will make Make compile Minisat again." > "$@"

compile_cryptominisat: cryptominisat
	cd cryptominisat && mkdir -p build && cd build && cmake -DENABLE_PYTHON_INTERFACE=OFF ..
	$(MAKE) -C cryptominisat/build
	echo "Removing this file will make Make compile CryptoMiniSat again." > "$@"

compile_lingeling: lingeling
	cd lingeling && ./configure.sh
	$(MAKE) -C lingeling
	echo "Removing this file will make Make compile lingeling again." > "$@"

compile_all: compile_minisat compile_cryptominisat compile_lingeling
