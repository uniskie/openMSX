# Creates the components header file.

from components import iterComponents
from makeutils import extractMakeVariables
from outpututils import rewriteIfChanged

import sys

def iterComponentsHeader(probeMakePath):
	probeVars = extractMakeVariables(probeMakePath)
	buildComponents = set(
		component.makeName
		for component in iterComponents()
		if component.canBuild(probeVars)
		)

	yield '// Automatically generated by build process.'
	yield ''
	yield '#ifndef COMPONENTS_HH'
	yield '#define COMPONENTS_HH'
	yield ''
	for component in iterComponents():
		varName = component.makeName
		yield '#define COMPONENT_%s %d' % (varName, varName in buildComponents)
	yield ''
	yield 'namespace openmsx {'
	yield ''
	yield 'static const char* const BUILD_COMPONENTS = "%s";' \
		% ' '.join(sorted(buildComponents))
	yield ''
	yield '} // namespace openmsx'
	yield ''
	yield '#endif // COMPONENTS_HH'

if __name__ == '__main__':
	if len(sys.argv) == 3:
		rewriteIfChanged(sys.argv[1], iterComponentsHeader(sys.argv[2]))
	else:
		print(
			'Usage: python3 components2code.py COMPONENTS_HEADER PROBE_MAKE',
			file=sys.stderr
			)
		sys.exit(2)
