all: minisat cryptominisat lingeling

LINGELING_VERSION=bal-2293bef-151109

minisat:
	git clone https://github.com/niklasso/minisat
	$(MAKE) compile_minisat

cryptominisat:
	git clone https://github.com/msoos/cryptominisat.git
	$(MAKE) compile_cryptominisat

lingeling:
	curl -o ll.tar.gz http://fmv.jku.at/lingeling/lingeling-$(LINGELING_VERSION).tar.gz
	tar xf ll.tar.gz
	mv lingeling-$(LINGELING_VERSION) lingeling
	$(RM) ll.tar.gz
	$(MAKE) compile_lingeling

.PHONY: compile_all \
  compile_minisat compile_cryptominisat compile_lingeling

compile_minisat:
	cd minisat && mkdir -p build && cd build && cmake ..
	$(MAKE) -C minisat/build

compile_cryptominisat:
	cd cryptominisat && mkdir -p build && cd build && cmake -DENABLE_PYTHON_INTERFACE=OFF ..
	$(MAKE) -C cryptominisat/build

compile_lingeling:
	cd lingeling && ./configure.sh
	$(MAKE) -C lingeling

compile_all: compile_minisat compile_cryptominisat compile_lingeling
