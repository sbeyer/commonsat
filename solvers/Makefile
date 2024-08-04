all: compile_all

PICOSAT_VERSION=965

minisat:
	# https://github.com/niklasso/minisat is unmaintained and does not compile, hence we use a fork
	git clone -b fix-c++ https://github.com/spakin/minisat

# dependency of cryptominisat
cadical:
	git clone -b mate-only-libraries-1.8.0 https://github.com/meelgroup/cadical
	cd cadical && ./configure && make

# dependency of cryptominisat
cadiback:
	git clone -b mate https://github.com/meelgroup/cadiback
	cd cadiback && ./configure && make

cryptominisat: cadical cadiback
	git clone https://github.com/msoos/cryptominisat.git

lingeling:
	git clone https://github.com/arminbiere/lingeling

picosat:
	curl -o ps.tar.gz http://fmv.jku.at/picosat/picosat-$(PICOSAT_VERSION).tar.gz
	tar xf ps.tar.gz
	mv picosat-$(PICOSAT_VERSION) picosat
	$(RM) ps.tar.gz

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

compile_picosat: picosat
	cd picosat && ./configure.sh
	$(MAKE) -C picosat
	echo "Removing this file will make Make compile PicoSAT again." > "$@"

compile_all: compile_minisat compile_cryptominisat compile_lingeling compile_picosat
