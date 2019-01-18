#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QObject>
#include "column.h"
#include "utilities/qutils.h"

class PreferencesModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(bool			fixedDecimals			READ fixedDecimals				WRITE setFixedDecimals				NOTIFY fixedDecimalsChanged				)
	Q_PROPERTY(int			numDecimals				READ numDecimals				WRITE setNumDecimals				NOTIFY numDecimalsChanged				)
	Q_PROPERTY(bool			exactPValues			READ exactPValues				WRITE setExactPValues				NOTIFY exactPValuesChanged				)
	Q_PROPERTY(bool			dataAutoSynchronization	READ dataAutoSynchronization	WRITE setDataAutoSynchronization	NOTIFY dataAutoSynchronizationChanged	)
	Q_PROPERTY(bool			useDefaultEditor		READ useDefaultEditor			WRITE setUseDefaultEditor			NOTIFY useDefaultEditorChanged			)
	Q_PROPERTY(QString		customEditor			READ customEditor				WRITE setCustomEditor				NOTIFY customEditorChanged				)
	Q_PROPERTY(bool			useDefaultPPI			READ useDefaultPPI				WRITE setUseDefaultPPI				NOTIFY useDefaultPPIChanged				)
	Q_PROPERTY(int			customPPI				READ customPPI					WRITE setCustomPPI					NOTIFY customPPIChanged					)
	Q_PROPERTY(bool			whiteBackground			READ whiteBackground			WRITE setWhiteBackground			NOTIFY whiteBackgroundChanged			)
	Q_PROPERTY(double		uiScale					READ uiScale					WRITE setUiScale					NOTIFY uiScaleChanged					)
	Q_PROPERTY(QStringList	missingValues			READ missingValues													NOTIFY missingValuesChanged				)
	Q_PROPERTY(int			defaultPPI				READ defaultPPI					WRITE setDefaultPPI					NOTIFY defaultPPIChanged				)


public:
	explicit	 PreferencesModel(QObject *parent = 0);
				~PreferencesModel();

	int			customPPI()					const;
	int			numDecimals()				const;
	int			defaultPPI()				const	{ return _defaultPPI; }
	bool		fixedDecimals()				const;
	bool		exactPValues()				const;
	bool		dataAutoSynchronization()	const;
	bool		useDefaultEditor()			const;
	bool		useDefaultPPI()				const;
	bool		whiteBackground()			const;
	double		uiScale()					const;
	QString		customEditor()				const;
	QString		fixedDecimalsForJS()		const;
	QStringList	missingValues()				const;
	void		missingValuesToStdVector(std::vector<std::string> & out) const;

public slots:
	void setUiScale(double uiScale);
	void setCustomPPI(int customPPI);
	void setDefaultPPI(int defaultPPI);
	void setNumDecimals(int numDecimals);
	void setExactPValues(bool exactPValues);
	void setCustomEditor(QString customEditor);
	void setFixedDecimals(bool fixedDecimals);
	void setUseDefaultPPI(bool useDefaultPPI);
	void setWhiteBackground(bool whiteBackground);
	void setUseDefaultEditor(bool useDefaultEditor);
	void setDataAutoSynchronization(bool dataAutoSynchronization);

	void browseSpreadsheetEditor();
	void updateUtilsMissingValues();
	void removeMissingValue(QString value);
	void addMissingValue(QString value);
	void resetMissingValues();

signals:
	void fixedDecimalsChanged(bool fixedDecimals);
	void fixedDecimalsChangedString(QString fixedDecimals);
	void numDecimalsChanged(int numDecimals);
	void exactPValuesChanged(bool exactPValues);
	void dataAutoSynchronizationChanged(bool dataAutoSynchronization);
	void useDefaultEditorChanged(bool useDefaultEditor);
	void customEditorChanged(QString customEditor);
	void useDefaultPPIChanged(bool useDefaultPPI);
	void whiteBackgroundChanged(bool whiteBackground);
	void uiScaleChanged(double uiScale);
	void customPPIChanged(int customPPI);
	void defaultPPIChanged(int defaultPPI);
	void missingValuesChanged();

	void plotPPIChanged(int ppiForPlot);
	void plotBackgroundChanged(QString background);

private:

	int _defaultPPI = 192;
};

#endif // PREFERENCESDIALOG_H