%modules = ( # path to module name map
    "QtDeclarative" => "$basedir/src/declarative",
);
# Module dependencies.
# Every module that is required to build this module should have one entry.
# Each of the module version specifiers can take one of the following values:
#   - A specific Git revision.
#   - any git symbolic ref resolvable from the module's repository (e.g. "refs/heads/master" to track master branch)
#
%dependencies = (
    "qtbase" => "refs/heads/dev",
    "qtscript" => "refs/heads/dev",
    "qtxmlpatterns" => "refs/heads/dev",
    "qtdeclarative" => "refs/heads/dev",
    "qtjsbackend" => "refs/heads/dev",
    "qtactiveqt" => "refs/heads/dev",
    "qttools" => "refs/heads/dev",
    "qtwebkit" => "refs/heads/dev",
);
